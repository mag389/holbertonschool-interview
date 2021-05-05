#!/usr/bin/python3
""" script to scrape and count words from reddit hot posts
"""
from operator import itemgetter
import requests


def recurse(subreddit, hot_list=[], after=""):
    """ uses reddit api to give top 10 hot posts
        in a subreddit
    """
    custom_user = {"User-Agent": "custom"}
    url = "https://www.reddit.com/r/" + subreddit + "/hot.json"
    params = {'after': after}
    res = requests.get(url,
                       headers=custom_user, params=params,
                       allow_redirects=False)

    if res.status_code != 200:
        return None
    else:
        info = res.json()
        children = info.get('data').get('children')
        for child in children:
            hot_list.append(child.get('data').get("title"))
        after = info.get('data').get('after')
        if after == 'null' or after is None:
            return (hot_list)
        return (recurse(subreddit, hot_list, after))


def count_words(subreddit, word_list, count_list=[]):
    """  counts occurences of words in hot subreddit title list """
    title_list = recurse(subreddit, [], "")
    if type(title_list) is not list:
        return
    # title_list = " ".join(title_list).lower().split()
    # word_dict = count_occurs(" ".join(title_list).lower(), word_list)
    word_dict = count_occurs(title_list, word_list)
    print_occurs(word_dict)


def count_occurs(title_list, word_list, word_dict={}):
    """ counts occurences, but only counts once per title """
    # print(word_list)
    # print("and")
    # print(word_dict)
    word = word_list[-1].lower()
    if word not in word_dict.keys():
        word_dict[word] = 0
    for title in title_list:
        if word in title.lower().split():
            # if word == "react":
            #     print(title)
            word_dict[word] += title.lower().split().count(word)
    word_list.pop()
    if len(word_list) < 1:
        return word_dict
    return count_occurs(title_list, word_list, word_dict)


# this also counts mutiples more than once
def icount_occurs(title_list, word_list, word_dict={}):
    """ counts occurences of words in a list of titles """
    word = word_list[-1].lower()
    if word in word_dict.keys():
        word_dict[word] += title_list.count(word)
    else:
        word_dict[word] = title_list.count(word)
    word_list.pop()
    if len(word_list) < 1:
        return word_dict
    return icount_occurs(title_list, word_list, word_dict)


def print_occurs(word_dict):
    """ sorts the dict to pass to printer """
    lst = sorted(word_dict.items(), key=lambda x: (-x[1], x[0]))
    # print(lst)
    print_lst(lst)
    return lst


def print_lst(sorted_list):
    """ print the list of words and numbers """
    if len(sorted_list) < 1:
        return None
    tupword = sorted_list.pop(0)
    if tupword[1] == 0:
        print_lst(sorted_list)
    else:
        print(tupword[0] + ": ", end="")
        print(tupword[1])
        print_lst(sorted_list)

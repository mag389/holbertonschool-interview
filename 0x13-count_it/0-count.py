#!/usr/bin/python3
""" script to scrape and count words from reddit hot posts
"""
import requests
import time
import urllib
import sys


def recurse(subreddit, word_list, hot_list=[], after=""):
    """ uses reddit api to give top 10 hot posts
        in a subreddit
    """
    custom_user = {"User-Agent": "custom"}
    url = "https://www.reddit.com/r/" + subreddit + "/hot.json"
    params = {'after': after}
    # print("right before request")
    res = requests.get(url,
                       headers=custom_user, params=params,
                       allow_redirects=False)
    # print(res.status_code)
    if res.status_code != 200:
        return(None)
    else:
        info = res.json()
        children = info.get('data').get('children')
        if children is None or len(children) == 0:
            print("in the if")
            return (hot_list)
        for child in children:
            hot_list.append(child.get('data').get("title"))
        # child = children[len(children) - 1]
        # title = child.get('data').get("title")
        # print(title)
        # hot_list.append(child.get('data').get("title"))
        after = info.get('data').get('after')
        # print(after)
        if after == 'null' or after is None:
            return (hot_list)
        return (recurse(subreddit, word_list, hot_list, after))


def count_words(subreddit, word_list, count_list=[]):
    """ counts occurences of words in hot subreddit title list """
    title_list = recurse(subreddit, word_list, [], "")
    if type(title_list) is not list:
        return
    title_list = " ".join(title_list).lower().split()
    # print(title_list)
    word_dict = count_occurs(" ".join(title_list).lower(), word_list)
    # word_dict = icount_occurs(title_list, word_list)
    print_occurs(word_dict)
    return None


def count_occurs(title_block, word_list, word_dict={}):
    """ count words without .count() """
    import re
    word = word_list[-1].lower()
    if word in word_dict.keys():
        word_dict[word] += len(re.findall(word + '(?!\w+)', title_block,
                                          flags=re.IGNORECASE))
        # word_dict[word] += title_block.count(word)
    else:
        word_dict[word] = len(re.findall(word + '(?!\w+)', title_block,
                                         flags=re.IGNORECASE))
        # word_dict[word] = title_block.count(word)
    word_list.pop()
    if len(word_list) < 1:
        return word_dict
    return count_occurs(title_block, word_list, word_dict)


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
    return count_occurs(title_list, word_list, word_dict)


def print_occurs(word_dict):
    """ prints the dictionary sorted """
    from operator import itemgetter
    lst = sorted(word_dict.items(), key=itemgetter(1))
    print_lst(lst)
    return lst


def print_lst(sorted_list):
    """ print the list of words and numbers """
    if len(sorted_list) < 1:
        return None
    tupword = sorted_list.pop()
    if tupword[1] == 0:
        print_lst(sorted_list)
    else:
        print(tupword[0] + ": ", end="")
        print(tupword[1])
        print_lst(sorted_list)

#!/usr/bin/python3
""" script to scrape and count words from reddit hot posts
"""
import requests
import time
import urllib
import sys


def recurse(subreddit, hot_list=[], after=""):
    """ uses reddit api to give top 10 hot posts
        in a subreddit
    """
    custom_user = {"User-Agent": "custom"}
    url = "https://www.reddit.com/r/" + subreddit + "/hot.json"
    print(url)
    if after == "":
       params = {'limit': 1, 'count': 1}
    else:
       params = {'limit': 1, 'count': 1, 'after': after}
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
        # print(info)
        children = info.get('data').get('children')
        if children is None or len(children) == 0:
            return (hot_list)
        for child in children:
            hot_list.append(child.get('data').get("title"))
        # child = children[len(children) - 1]
        # title = child.get('data').get("title")
        # print(title)
        # hot_list.append(child.get('data').get("title"))
        after = info.get('data').get('after')
        print(after)
        if after == 'null' or after is None:
            return (hot_list)
        return (recurse(subreddit, hot_list, after))

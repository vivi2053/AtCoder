import unicodedata
import re

import unicodedata
import re

example = "　生命 、宇宙　、そして 万物に ついて の究極 の疑問    の答え　は　42"


def remove_extra_spaces(example):

    # normalizing whitespace chars to half-width space
    e = example.strip()
    e = e.replace('\t', ' ')
    e = re.sub("\u200b", "", e)
    e = re.sub("[ 　]+", " ", e)

    ja_cls = "".join(
        (
            "\u4E00-\u9FFF",  # CJK UNIFIED IDEOGRAPHS
            "\u3040-\u309F",  # HIRAGANA
            "\u30A0-\u30FF",  # KATAKANA
            "\u3000-\u303F",  # CJK SYMBOLS AND PUNCTUATION
            "\uFF00-\uFFEF",  # HALFWIDTH AND FULLWIDTH FORMS
        )
    )
    latin_cls = "".join(
        (
            "\u0000-\u007F",  # BASIC LATIN[g]
            "\u0080-\u00FF",  # LATIN-1 SUPPLEMENT[h]
        )
    )

    def remove_space_between(char_cls1, char_cls2, e):
        p = re.compile("([{}]) ([{}])".format(char_cls1, char_cls2))
        while p.search(e):
            e = p.sub(r"\1\2", e)
        return e

    e = remove_space_between(ja_cls, ja_cls, e)
    e = remove_space_between(ja_cls, latin_cls, e)
    e = remove_space_between(latin_cls, ja_cls, e)
    return e


print(remove_extra_spaces(example))

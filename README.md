# What's this?
[Android Native で SIGSEGV が起きたときに Java 例外を VM に通知する](http://d.hatena.ne.jp/s5r/20120726/1343305884)

## なにが嬉しいの?
Android だと例外が起きたときに Play マーケットに報告できたり (デベロッパーはユーザの報告を確認できる) 、 ACRA を使って例外が起きた状況を調べることが出来るが、 Native 側で死ぬと静かにプロセスが殺されるだけなので確認する手段が無い。
しかし、 Java 例外にしてしまえば調べることが出来る。素晴しい。

# License
Released under the Apache License, v2.0.


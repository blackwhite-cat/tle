TLE
====
TLE(2行軌道要素形式)から人工衛星の各種軌道要素を取得するプログラム

概要
----
TLEは[NORAD Two-Line Element Sets](http://celestrak.com/NORAD/elements/)などから入手することができる<br>
TLEは下図のようなフォーマットで記述されている<br>
![tle](data/TLE.png)<br>
このプログラムはこれらのデータを解読する<br>
Line 1とLine 2のチェックサムは利用せずに捨てている

要求
----
 * [Microsoft Visual Studio Community 2017](https://www.microsoft.com/ja-jp/dev/products/community.aspx)<br>
 * [Windows SDK](https://developer.microsoft.com/ja-jp/windows/downloads/windows-8-1-sdk)<br>

ライセンス
----
MITライセンスで公開する<br>
詳しくは[LICENSE.md](LICENSE.md)を参照すること

参考
----
[2行軌道要素形式(Wikipedia)](https://ja.wikipedia.org/wiki/2%E8%A1%8C%E8%BB%8C%E9%81%93%E8%A6%81%E7%B4%A0%E5%BD%A2%E5%BC%8F)

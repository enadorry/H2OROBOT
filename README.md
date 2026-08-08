# H2OROBOT
H2O ROBOT Program &amp; source code
<br>README 最終更新日 2026/8/8
<br>OSS
<br>MIT License
<br>水中ロボットをスマホで簡単に操作できるようなアプリです。
<br>スマホからESP32などにWi-Fi(UDP)で送信し操作でき、コントローラーで操作できます。
<br>確認できる範囲では、Android13以上で動作します。
<br>水中ロボで配布されたESP32Devで動作します
<br>DualSenseなどのコントローラーをスマホに接続すればスティックや十字キーで操作可能です。
# 使用前の注意
こちらのコードは基本転載もプログラムの変更も好きにやってもらって構いませんが、以下のルールを順守してください。
<br><li>戦争や人に危害をもたらすようなことに使用を禁止。
<br><li>改造などをして再配布する際は、@Enadorry.2009やhttps://twitter.com/scarlet_shuu などのハンドルネームや連絡先をどこかに貼ってくれれば幸いです。
<br><li>商用的な利用はTwitterやDiscordなどで連絡お願いします。
<br><li>その他、ご不明な点があれば連絡お願いします。

# ビルド方法
<br>UnityのパッケージはH20_ROBOT.unitypackage で Arduinoのプログラムは kibann.ino.inoです(名前訂正せねば)
<br>※iPhoneとMac使用者はぐぐってください
<br>Androidでのapk作成方法
<br>Unityのバージョンは6000.3.7f1を使用することを推奨します
<br>[https://adsnetwork-docs.linebiz.com/fivesdk-unity/quick-start/install-unitypackage.html](https://yttm-work.jp/unity_beginner/unity_beginner_0008.html#head_line_02)
<br>こちらのサイトがわかりやすかったので参考にして下さい
<br>外部パッケージというやり方で行って下さい
<br>次にAndroidで使えるようにapkにビルドしてください
<br>https://shibuya24.info/entry/unity-build-android
<br>こちらのサイトを参考にしてビルド作業を行ってください。りんごはしりません
<br><strong>ビルドする際は 編集→プレイヤー→解像度と表示→自動回転が可能の向きの 縦向きと縦向き（逆）のチェックマークを外してください!</strong>
<br>後は手順に従ってビルド作業を進めたらできると思います

# 使用方法

アプリを開く前に、ESP32Devから出てるWi-FIに接続して下さい
<br><strong>アプリを開いてから接続作業を行っても、反応しません</strong>
<br>SSIDとパスワードは各自設定して書き込んでください。
<br><br>ESPへのkibann.inoの書き込み方法については省略させていただきます<br>調べてもらえれば幸いです

# 連絡先
<li>Discord:@enadorry.2009</li>

# トラブルシューティング
・動きません
<br>　⇒まずはしっかりスマホとESPがWi-Fiで接続できてるかを確認してください。
<br>　もし接続していても動作しない場合は、モバイル通信をOFFにしてください。192.168.11.1が外の世界の方へデータを送ろうとしているためです。
<br>　もしモバイル通信がOFFでも動作しない場合は、一旦アプリを閉じて、タスクキルして、もう一回アプリを起動しなおしてください。
<br>　体感これが動かないトラブルの原因で、その解決方法です。
<br>・アプリのコンパイルがよくわからない
<br>　⇒APKとiOS向けそろそろ配布します...そういうトラブルを殺さなければ... なのでもうしばらくお待ちいただければ幸いです。


# 追記
<br>iPhoneへのビルド方法についてはめっちゃ雑に放り投げました。本当に申し訳ございません。
<br>iPhoneは日本では使用率が高いものなので、私が怠惰にならなければ後日ちゃんとアプリ作ります。
<br>引退?みたいな感じですが、プログラムの改善等は今後とも尽力していきますし、アドバイスや改善などあれば連絡等していただければ、期待に応える限り改善していこうと思います。
<br>最後にですが、このソフトウェアを使用してくださり本当にうれしい限りです。
<br><br>written&made by enadorry.2009
<br><br>Thank you for "H2O" teammember,
<br>And All App user.

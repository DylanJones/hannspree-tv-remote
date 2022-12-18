I've got a Hannspree HSG1102 TV that we got without a remote.  I wanted to make my own remote using an IR LED and an ESP32, but I couldn't find anything on the Internet describing the IR protocol the remote uses.

### Universal Remote Codes and the IRDB
Since I already knew I was going to be using an ESP32 and a bare IR LED to transmit the control codes,
I started off by finding a library to do the heavy lifting for me. [Arduino-IRRemote](https://github.com/Arduino-IRremote/Arduino-IRremote)
does exactly what I want - it supports all kinds of IR protocols, and allows you to transmit basically anything that you could possibly want.
However, I'm missing the original remote for this TV, which means I don't know _what_ data to send, or even which protocol to use.

For most modern TVs, the remote codes can be found in the [IRDB](https://github.com/probonopd/irdb/tree/master/codes).  However,
Hannspree isn't on that big list, and I couldn't find it in any of the other linked resources.

I wasn't able to find any documentation at all on the protocol that the Hannspree HSG1102 used, but I was able
to find an [Android app](https://play.google.com/store/apps/details?id=com.weedle.tv_hannspree_remotes&hl=en_GB&gl=US&pli=1)
that claimed to be able to control the TV.
<!-- Play store screenshot -->
I pulled out an old phone with an IR blaster, downloaded the app, and started it up.  After selecting the remote option for the Hannspree TV, there was a quick "downloading" progress bar while it downloaded the remote codes from the Internet, and then it finally loaded into a picture of the remote with buttons on the screen.  Tapping the buttons activated the IR blaster and sent the commands to the TV, just like the original remote would have!


### Reverse Engineering the Android App
I first started out by downloading the app, installing it to an old phone with an IR blaster, and confirming that it was able to control the TV.  While using it, I noticed that it had to download the remote codes after I selected the model, which gave me the clue that the IR data was most likely being downloaded over the Internet somehow.  I downloaded a copy of the APK, unzipped it, then used [dex2jar](a) and [Fernflower]()

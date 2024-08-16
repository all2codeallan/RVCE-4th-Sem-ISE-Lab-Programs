# Experiment 7: Water sensing and sending information to email using water sensor interfacing with Raspberry Pi

## Setup Instructions
- For the `From` email address (not RVCE email), either use an existing gmail account or create a new one.
- From your gmail inbox, you will be able to go to your google account settings by clicking the `Manage your Google Account` button. (Exists near the sign out button)
- Go to `Security` and turn on `2-Step Verification`.
- This unlocks `App Passwords` option which you can access by using the search bar given above.
- Now enter a App Name (can be anything) and click on Create. An app password will be generated and displayed as `aaaa aaaa aaaa aaaa`.
- Copy it and save it somwehere in a text file. In the `password` variable in the code enter this app password while removing all spaces in between.
- The `To` address can be any other gmail address. (Preferably 2-step verification can be turned off for this email).

- To use the `RVCE` address as your `From` address, you can go to your google account settings (same as above) and go to `Security` where you can turn on `Less Secure App Access` option. This should do it and now you enter your email password itself for the `password` variable in the code.


## Circuit Setup
- Connect water sensor's `OUT/Signal` pin to Board pin 18.
- Connect Buzzer to Board pin 11.
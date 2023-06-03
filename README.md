## usage

1. open GitHub Desktop

2. fetch changes from cloud

[fetch](fetch.gif)

3. run main.maxpat


## comms

osc host ip: 10.0.0.2

sensor A send

| ip | port | address |
| ---- | --- | ---- |
| 10.0.0.11 | 9911 | /distance |
| local | 9921 | /trigger |

sensor B send

| ip | port | address |
| ---- | --- | ---- |
| 10.0.0.12 | 9912 | /distance |
| local | 9922 | /trigger |

pump receive

| ip | port | address |
| ---- | --- | ---- |
| 10.0.0.13 | 9913 | /pwm |

kinect send to Max

| ip | port | address |
| ---- | --- | ---- |
| local | 9930 | /p1 /p2 etc |

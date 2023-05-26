osc host ip: 10.0.0.2

sensor A send

| ip | port | address |
| ---- | --- | ---- |
| 10.0.0.11 | 9911 | /distance |
| 10.0.0.11 | 9911 | /trigger |

sensor B send

| ip | port | address |
| ---- | --- | ---- |
| 10.0.0.12 | 9912 | /distance |
| 10.0.0.12 | 9912 | /trigger |

pump receive

| ip | port | address |
| ---- | --- | ---- |
| 10.0.0.13 | 9913 | /pwm |

# Trackpoint-Config-OSX

Config Utility for ThinkPad TrackPoint Bluetooth Keyboards for OSX

## Features
* Maximize Trackpoint Sensitivity
* Disable middle-click (only scrolling with Trackpoint)

## Support Models
- ThinkPad Compact Bluetooth Keyboard with TrackPoint (0B47189)
- ThinkPad TrackPoint Keyboard II

## Install
1. `make install`
2. `sudo tpkb`

## Tuning/Customize
### Mouse Speed
`defaults write -g com.apple.mouse.scaling 9` (Re-login required)
replace 9 to any you want, the max you can set from SystemPreferce GUI is 3

### Trackpoint
modify file `src/tp.cpp`, replace `0x09` to any you want
``` cpp
    // sensitivity
    // 18 02 xx   # xx Sensitivity, 00-FF
    buf[0] = 0x18;
    buf[1] = 0x02;
    buf[2] = 0x09;
    hid_write(dev, buf, 3);
```

## Adapted from
- https://github.com/unknownzerx/tpkb
- https://github.com/lentinj/tp-compact-keyboard


enjoy :)
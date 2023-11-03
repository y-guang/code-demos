# Detect Display Change Event

ref: ChatGPT

## idea

The idea is when display info change, all top level windows will receive a `WM_DISPLAYCHANGE` message. So we need to built an invisible window to receive this message.
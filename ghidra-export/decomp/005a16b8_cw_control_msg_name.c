// func cw_control_msg_name @ 005a16b8 size=92

char * cw_control_msg_name(int param_1)

{
  if (param_1 - 1U < 0x1a) {
    return (&PTR_s_Discovery_Request_006e63b8)[param_1 - 1U];
  }
  if (param_1 - 0x33dd01U < 2) {
    return (&PTR_s_IEEE_802_11_WLAN_Configuration_R_006e6420)[param_1 - 0x33dd01U];
  }
  return "-INVALID_MSG_TYPE-";
}


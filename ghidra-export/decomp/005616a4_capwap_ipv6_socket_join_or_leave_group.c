// func capwap_ipv6_socket_join_or_leave_group @ 005616a4 size=228

undefined4 capwap_ipv6_socket_join_or_leave_group(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  inet_pton(10,"FF0E::18C",&local_28);
  local_18 = param_2;
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    if (param_3 == 0) {
      pcVar2 = "Leave";
    }
    else {
      pcVar2 = "Join";
    }
    printf("[CW_DEBUG]%32s():%4d %s multicast group for interface:%d\n",
           "capwap_ipv6_socket_join_or_leave_group",0x1ee,pcVar2,local_18);
  }
  iVar1 = 0x15;
  if (param_3 != 0) {
    iVar1 = 0x14;
  }
  setsockopt(param_1,0x29,iVar1,&local_28,0x14);
  return 0;
}


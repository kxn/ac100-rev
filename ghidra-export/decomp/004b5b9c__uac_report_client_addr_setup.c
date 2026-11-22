// func _uac_report_client_addr_setup @ 004b5b9c size=448

undefined4 _uac_report_client_addr_setup(void)

{
  uint uVar1;
  addrinfo *__ai;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  addrinfo *local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : _uac_report_client_addr_setup\n",
           "_uac_report_client_addr_setup",0x6b);
  }
  local_28 = (addrinfo *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  DAT_00767ea0 = 0;
  DAT_00767e88 = 0;
  DAT_00767e8c = 0;
  DAT_00767e90 = 0;
  DAT_00767e94 = 0;
  DAT_00767e98 = 0;
  DAT_00767e9c = 0;
  DAT_00767e78 = 0;
  DAT_00767e7c = 0;
  DAT_00767e80 = 0;
  local_18 = 0;
  local_14 = 0;
  DAT_00767e74 = (uint)DAT_00767e6c._2_2_;
  DAT_00767e84 = (uint)DAT_00767e6c._2_2_;
  iVar2 = FUN_0051a7a8(&DAT_00767d71,&local_24);
  uVar1 = local_24 >> 0x18;
  if (iVar2 == 0) {
    DAT_00767ea0 = uVar1;
    if (uVar1 == 1) {
      DAT_00767e78 = local_20;
      DAT_00767e74 = CONCAT22(2,DAT_00767e74._2_2_);
    }
    else {
      memcpy(&DAT_00767e8c,&local_20,0x10);
      DAT_00767e84 = CONCAT22(10,DAT_00767e84._2_2_);
    }
    uVar5 = 0;
  }
  else {
    iVar2 = getaddrinfo(&DAT_00767d71,(char *)0x0,(addrinfo *)0x0,&local_28);
    __ai = local_28;
    if (iVar2 == 0) {
      memcpy(&DAT_00767e74,local_28->ai_addr,0x10);
      DAT_00767ea0 = 1;
      DAT_00767e74 = CONCAT22(2,DAT_00767e74._2_2_);
      freeaddrinfo(__ai);
      uVar5 = 0;
    }
    else {
      if (report_warning_switch != 0) {
        piVar3 = __errno_location();
        pcVar4 = strerror(*piVar3);
        printf("[REPORT_WARNING]%s()/line %d : _addr_to_sockaddr, getaddrinfo fail, err = %s\n",
               "_addr_to_sockaddr",0x58,pcVar4);
      }
      uVar5 = 0xffffffff;
      if (local_28 != (addrinfo *)0x0) {
        freeaddrinfo(local_28);
      }
    }
  }
  return uVar5;
}


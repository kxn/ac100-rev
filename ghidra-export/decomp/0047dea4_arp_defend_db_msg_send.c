// func arp_defend_db_msg_send @ 0047dea4 size=176

undefined4 arp_defend_db_msg_send(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_18;
  int local_14;
  
  if (param_2 != 0) {
    local_18 = param_1;
    local_14 = param_2;
    FUN_00407e80("arp_defend_db_msg_send");
    uVar1 = FUN_00407d40(g_arp_defend_msgq,&local_18,8,200,10000);
    FUN_004082b0(1,"arp_defend_db_msg_send");
    if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d uac_msgQ_send(), ret = %d\n","arp_defend_db_msg_send",0x8ba,
             uVar1);
    }
  }
  return 0;
}


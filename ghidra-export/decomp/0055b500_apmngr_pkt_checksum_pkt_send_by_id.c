// func apmngr_pkt_checksum_pkt_send_by_id @ 0055b500 size=604

undefined4 apmngr_pkt_checksum_pkt_send_by_id(uint param_1,byte *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  char *__format;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  
  param_1 = param_1 & 0xffff;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  serv_wtp_address_arg_init(&local_28);
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_28,1,1,0xffffffff,1,4);
  if (iVar1 == 0) {
    if (local_20 == 0) {
      iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_28,1,1,0xffffffff,1,0x33);
      if (iVar1 != 0) {
        if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          __format = "[APMNGR_ERROR]%s()/%d apmngr_db_get_addr_by_capacity fail\n";
          uVar2 = 0xb52;
          goto LAB_0055b6f8;
        }
        goto LAB_0055b6bc;
      }
      if (local_20 != 0) goto LAB_0055b57c;
      if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APMNGR_DEBUG]%s()/%d Don\'t send checksum because AP do not support MULTI-LINK or checksum feature or is not master.\n"
               ,"apmngr_pkt_checksum_pkt_send_by_id",0xb57);
      }
    }
    else {
LAB_0055b57c:
      if ((apmngr_timer_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APMNGR_TIMER]%s()/%d send ap[%d] MD5: \n","apmngr_pkt_checksum_pkt_send_by_id",
               0xb5c,param_1);
      }
      if (apmngr_timer_switch != '\0') {
        iVar1 = 0;
        pbVar3 = param_2;
        do {
          iVar1 = iVar1 + 1;
          printf("%02X-",(uint)*pbVar3);
          pbVar3 = param_2 + iVar1;
        } while (iVar1 != 0xf);
        printf("%02X\r\n",(uint)param_2[0xf]);
      }
      iVar1 = apmngr_pkt_checksum_pkt_send(&local_28,param_2);
      if (iVar1 != 0) {
        if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          __format = "[APMNGR_ERROR]%s()/%d apmngr_pkt_checksum_pkt_send() fail.\n";
          uVar2 = 0xb68;
          goto LAB_0055b6f8;
        }
        goto LAB_0055b6bc;
      }
    }
    serv_wtp_address_arg_destroy(&local_28);
    uVar2 = 0;
  }
  else {
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "[APMNGR_ERROR]%s()/%d apmngr_db_get_addr_by_capacity fail\n";
      uVar2 = 0xb4a;
LAB_0055b6f8:
      printf(__format,"apmngr_pkt_checksum_pkt_send_by_id",uVar2);
    }
LAB_0055b6bc:
    serv_wtp_address_arg_destroy(&local_28);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


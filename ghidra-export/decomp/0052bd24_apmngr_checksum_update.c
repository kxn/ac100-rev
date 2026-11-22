// func apmngr_checksum_update @ 0052bd24 size=1076

undefined4 apmngr_checksum_update(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  void *__s2;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    if (param_2 == 1) {
      puVar1 = &DAT_006c5a90;
    }
    else {
      puVar1 = &DAT_006c5a94;
    }
    printf("[APMNGR_DEBUG]%s()/%d apmngr_checksum_update id[%d] send_pkt :%s \n",
           "apmngr_checksum_update",0x4d4,(uint)*(ushort *)(param_1 + 0x10),puVar1);
  }
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if (param_1 == 0) {
    uVar4 = 0xffffffff;
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Input ap entry is NULL.\n";
    uVar3 = 0x4db;
LAB_0052bdf4:
    printf(__format,"apmngr_checksum_update",uVar3);
    return uVar4;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar4 = 0;
    if (apmngr_debug_switch == '\0') {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    __format = "[APMNGR_DEBUG]%s()/%d template need not caculate checksum.\n";
    uVar3 = 0x4e1;
    goto LAB_0052bdf4;
  }
  if (1 < *(int *)(param_1 + 0x2ac) - 1U) {
    if (apmngr_warning_switch == '\0') {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[APMNGR_WARNING]%s()/%d forbid update checksum when state is %d\n",
           "apmngr_checksum_update",0x4e6,*(undefined4 *)(param_1 + 0x2ac));
    return 0;
  }
  iVar2 = apmngr_db_checksum_get(*(undefined2 *)(param_1 + 0x10),&local_28);
  if (iVar2 != 0) {
    uVar4 = 0xffffffff;
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d apmngr_db_checksum_get() fail.\n";
    uVar3 = 0x4eb;
    goto LAB_0052bdf4;
  }
  iVar2 = apmngr_checksum_caculate(param_1);
  if (iVar2 != 0) {
    uVar4 = 0xffffffff;
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d apmngr_checksum_caculate() fail.\n";
    uVar3 = 0x4f0;
    goto LAB_0052bdf4;
  }
  __s2 = (void *)(param_1 + 0x29a);
  apmngr_db_checksum_update(*(undefined2 *)(param_1 + 0x10),__s2);
  if (param_2 == 0) {
    return 0;
  }
  iVar2 = memcmp(&local_28,__s2,0x10);
  if (((iVar2 == 0) && (apmngr_debug_switch != '\0')) &&
     (iVar2 = is_target_debug_ap(&local_38), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d md5 doesn\'t change.\n","apmngr_checksum_update",0x4fd);
  }
  serv_wtp_address_arg_init(&local_38);
  iVar2 = apmngr_db_get_addr_by_capacity
                    (*(undefined2 *)(param_1 + 0x10),&local_38,1,1,0xffffffff,1,4);
  if (iVar2 == 0) {
    if (local_30 == 0) {
      iVar2 = apmngr_db_get_addr_by_capacity
                        (*(undefined2 *)(param_1 + 0x10),&local_38,1,1,0xffffffff,1,0x33);
      if (iVar2 != 0) goto LAB_0052c148;
      if (local_30 == 0) {
        if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(&local_38), iVar2 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d Don\'t send checksum because AP do not support MULTI-LINK or checksum feature or is not master.\n"
                 ,"apmngr_checksum_update",0x50f);
        }
        goto LAB_0052c034;
      }
    }
    if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d send ap[%d] MD5: \n","apmngr_checksum_update",0x514,
             (uint)*(ushort *)(param_1 + 0x10));
    }
    if (apmngr_debug_switch != '\0') {
      iVar5 = 0;
      iVar2 = param_1;
      do {
        iVar5 = iVar5 + 1;
        printf("%02X-",(uint)*(byte *)(iVar2 + 0x29a));
        iVar2 = param_1 + iVar5;
      } while (iVar5 != 0xf);
      printf("%02X\r\n",(uint)*(byte *)(param_1 + 0x2a9));
    }
    iVar2 = apmngr_pkt_checksum_pkt_send(&local_38,__s2);
    if (iVar2 == 0) {
LAB_0052c034:
      serv_wtp_address_arg_destroy(&local_38);
      return 0;
    }
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(&local_38), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d apmngr_pkt_checksum_pkt_send() fail.\n","apmngr_checksum_update"
             ,0x520);
    }
  }
LAB_0052c148:
  serv_wtp_address_arg_destroy(&local_38);
  return 0xffffffff;
}


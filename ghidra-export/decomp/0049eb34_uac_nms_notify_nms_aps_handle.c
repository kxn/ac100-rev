// func uac_nms_notify_nms_aps_handle @ 0049eb34 size=724

undefined4 uac_nms_notify_nms_aps_handle(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  char *__s;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char local_420 [20];
  char acStack_40c [260];
  undefined1 auStack_308 [72];
  byte local_2c0;
  byte local_2bf;
  byte local_2be;
  byte local_2bd;
  byte local_2bc;
  byte local_2bb;
  char local_143;
  int local_30;
  
  memset(acStack_40c,0,0x100);
  if (param_2 == (byte *)0x0) {
    iVar5 = g_nms_aps_support_cnt * 0x12;
    __s = (char *)FUN_00408450(iVar5 + 0x25U,0x158);
    if (__s != (char *)0x0) {
      memset(__s,0,iVar5 + 0x25U);
      local_420[0] = '\0';
      local_420[1] = '\0';
      local_420[2] = '\0';
      local_420[3] = '\0';
      local_420[4] = '\0';
      local_420[5] = '\0';
      local_420[6] = '\0';
      local_420[7] = '\0';
      local_420[8] = '\0';
      local_420[9] = '\0';
      local_420[10] = '\0';
      local_420[0xb] = '\0';
      pcVar8 = __s + 10;
      local_420[0xc] = '\0';
      local_420[0xd] = '\0';
      local_420[0xe] = '\0';
      local_420[0xf] = '\0';
      local_420[0x10] = '\0';
      local_420[0x11] = '\0';
      memset(auStack_308,0,0x2d8);
      local_30 = apmngr_db_get_ap_max();
      iVar1 = g_nms_aps_support_cnt;
      if (((pcVar8 != (char *)0x0) && (0 < iVar5)) && (g_nms_aps_support_cnt * 0x12 <= iVar5)) {
        iVar7 = 0;
        iVar5 = 0;
        uVar6 = 0;
        while (((int)uVar6 < local_30 && (iVar7 < iVar1))) {
          memset(auStack_308,0,0x2d8);
          iVar2 = apmngr_db_entry_get_by_id(uVar6 & 0xffff,auStack_308);
          if (iVar2 == -1) {
LAB_0049ecf4:
            uVar6 = uVar6 + 1;
          }
          else {
            iVar2 = cloud_mngt_ap_is_nms_spupport(uVar6,0);
            if (iVar2 != 1) goto LAB_0049ecf4;
            if (local_143 == '\0') {
              uVar6 = uVar6 + 1;
            }
            else if (g_uac_nms_report_switch == 1) {
              if (g_nms_support_switch == 1) {
                local_420[0] = '\0';
                local_420[1] = '\0';
                local_420[2] = '\0';
                local_420[3] = '\0';
                local_420[4] = '\0';
                local_420[5] = '\0';
                local_420[6] = '\0';
                local_420[7] = '\0';
                local_420[8] = '\0';
                local_420[9] = '\0';
                local_420[10] = '\0';
                local_420[0xb] = '\0';
                local_420[0xc] = '\0';
                local_420[0xd] = '\0';
                local_420[0xe] = '\0';
                local_420[0xf] = '\0';
                local_420[0x10] = '\0';
                local_420[0x11] = '\0';
                snprintf(local_420,0x12,"%02x-%02x-%02x-%02x-%02x-%02x",(uint)local_2c0,
                         (uint)local_2bf,(uint)local_2be,(uint)local_2bd,(uint)local_2bc,
                         (uint)local_2bb);
                pcVar3 = pcVar8 + iVar5;
                if (iVar5 != 0) {
                  iVar5 = iVar5 + 1;
                  *pcVar3 = ',';
                }
                pcVar3 = pcVar8 + iVar5;
                iVar5 = iVar5 + 0x11;
                memcpy(pcVar3,local_420,0x11);
                iVar7 = iVar7 + 1;
                uVar6 = uVar6 + 1;
              }
              else {
                uVar6 = uVar6 + 1;
              }
            }
            else {
              uVar6 = uVar6 + 1;
            }
          }
        }
        if (0 < iVar7) {
          memcpy(__s,"\"ap_mac\":\"",10);
          sVar4 = strlen(__s);
          __s[sVar4] = '\"';
          (__s + sVar4)[1] = ',';
          local_uac_nms_notify_handle(param_1,__s,param_3);
        }
      }
      FUN_00407df0(__s);
    }
  }
  else {
    snprintf(acStack_40c,0x100,"\"ap_mac\":\"%02x-%02x-%02x-%02x-%02x-%02x\",",(uint)*param_2,
             (uint)param_2[1],(uint)param_2[2],(uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
    local_uac_nms_notify_handle(param_1,acStack_40c,param_3);
  }
  return 0;
}


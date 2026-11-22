// func radius_acct_update @ 00445d90 size=732

undefined4 radius_acct_update(char *param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_610 [4];
  char acStack_60c [44];
  undefined4 local_5e0;
  undefined1 auStack_5dc [255];
  undefined1 auStack_4dd [121];
  undefined1 auStack_464 [104];
  undefined4 local_3fc;
  undefined4 local_3f8;
  undefined4 local_3f4;
  undefined4 local_3f0;
  undefined4 local_3ec;
  undefined4 local_3dc;
  char acStack_1c4 [283];
  undefined1 auStack_a9 [6];
  undefined1 auStack_a3 [7];
  undefined1 auStack_9c [44];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 auStack_58 [48];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_610[0] = 0x31;
  memset(acStack_60c,0,0x28);
  uVar1 = 0xffffffff;
  if (*(int *)(param_1 + 0x19c) != 0) {
    memset(&local_5e0,0,0x5d0);
    local_5e0 = 4;
    local_68 = *(undefined4 *)(param_1 + 0x180);
    strncpy(acStack_1c4,param_1,100);
    memcpy(auStack_9c,param_1 + 0x184,0x14);
    memcpy(auStack_a9,param_1 + 0x65,6);
    memcpy(auStack_a3,param_1 + 0x6b,6);
    uac_ipaddr_convert_binary2str
              (*(undefined4 *)(param_1 + 0x1c8),*(undefined4 *)(param_1 + 0x1cc),
               *(undefined4 *)(param_1 + 0x1d0),*(undefined4 *)(param_1 + 0x1d4),
               *(undefined4 *)(param_1 + 0x1d8),acStack_60c,0x28,"0.0.0.0");
    sVar2 = strlen(acStack_60c);
    memcpy(auStack_5dc,acStack_60c,sVar2 + 1);
    local_3dc = *(undefined4 *)(param_1 + 0x19c);
    local_6c = *(undefined4 *)(param_1 + 0x17c);
    local_70 = *(undefined4 *)(param_1 + 0x178);
    memcpy(auStack_4dd,param_1 + 0xfe,0x78);
    memcpy(auStack_58,param_1 + 0x1a0,0x20);
    memcpy(auStack_464,param_1 + 0x71,100);
    iVar3 = uac_ipaddr_convert_str2binary(param_1 + 0xd6,&local_3fc);
    if (iVar3 != 0) {
      local_3fc = 0;
      local_3f8 = 0;
      local_3f4 = 0;
      local_3f0 = 0;
      local_3ec = 0;
    }
    local_24 = *(undefined4 *)(param_1 + 0x1e4);
    local_28 = *(undefined4 *)(param_1 + 0x1e0);
    local_1c = *(undefined4 *)(param_1 + 0x1ec);
    local_20 = *(undefined4 *)(param_1 + 0x1e8);
    local_18 = *(undefined4 *)(param_1 + 0x1f0);
    if (*(uint *)(PTR_DAT_007591ac + 0x1294) == 0) {
      trap(7);
    }
    uVar5 = DAT_00766ba8 % *(uint *)(PTR_DAT_007591ac + 0x1294);
    DAT_00766ba8 = DAT_00766ba8 + 1;
    iVar4 = uVar5 * 0x30;
    iVar3 = uac_msgQ_send(*(undefined4 *)(threads + iVar4),&local_5e0,0x5d0,3,2000);
    if (iVar3 == -1) {
      if (radius_debug_switch != 0) {
        printf("[RADIUS_DEBUG]%s()/%d Send to msgq error\n\n","radius_acct_update",0x13a3);
      }
      g_uac_msgQ_send_acct_update_fail_count = g_uac_msgQ_send_acct_update_fail_count + 1;
      uVar1 = 0;
    }
    else {
      write(*(int *)(threads + iVar4 + 8),local_610,1);
      uVar1 = 0;
    }
  }
  return uVar1;
}


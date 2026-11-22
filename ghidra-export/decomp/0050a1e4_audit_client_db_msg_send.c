// func audit_client_db_msg_send @ 0050a1e4 size=620

undefined4 audit_client_db_msg_send(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined1 local_28 [8];
  
  local_28[0] = 0x31;
  if ((param_2 == 0) || (param_4 == 0)) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[AUDIT_ERR]%s()/%d Data or free cb is null.\n";
    uVar3 = 0xdd;
LAB_0050a36c:
    printf(__format,"audit_client_db_msg_send",uVar3);
    return 0xffffffff;
  }
  if (audit_debug_switch != 0) {
    printf("[AUDIT_DBG]%s()/%d send msg, type=%d\n","audit_client_db_msg_send",0xe1,param_1);
  }
  iVar1 = FUN_004082a0(1,0x18,0xe3);
  if (iVar1 == 0) {
    if (audit_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[AUDIT_ERR]%s()/%d Memory is not enough.\n";
    uVar3 = 0xe6;
    goto LAB_0050a36c;
  }
  *(int *)(iVar1 + 0x14) = param_4;
  *(undefined4 *)(iVar1 + 0xc) = param_1;
  *(int *)(iVar1 + 0x10) = param_2;
  FUN_004082d0(DAT_0076891c,0xffffffff);
  if (DAT_0076890c < g_msg_max) {
    iVar2 = *(int *)(iVar1 + 0xc);
  }
  else {
    if (param_3 == 2) goto LAB_0050a428;
    iVar2 = FUN_00408610(&audit_msg_queue);
    FUN_00408500(iVar2);
    if (*(int *)(iVar2 + 0xc) == 2) {
      FUN_00408690(DAT_00768910,iVar1);
    }
    audit_client_db_msg_free(iVar2);
    iVar2 = *(int *)(iVar1 + 0xc);
  }
  if ((iVar2 != 2) || (iVar2 = FUN_00407e20(DAT_00768910,iVar1), iVar2 == 0)) {
    if (param_3 == 1) {
      FUN_00408240(&audit_msg_queue,iVar1);
    }
    else {
      FUN_004086b0();
    }
    if (audit_debug_switch != 0) {
      printf("[AUDIT_DBG]%s()/%d msg list size: %u\n","audit_client_db_msg_send",0x11b,DAT_0076890c)
      ;
    }
    if (DAT_0076890c == 1) {
      write(DAT_00768918,local_28,1);
    }
    FUN_00407f30(DAT_0076891c);
    return 0;
  }
LAB_0050a428:
  FUN_00407f30(DAT_0076891c);
  audit_client_db_msg_free(iVar1);
  return 0;
}


// func audit_client_db_msg_recv @ 0050a450 size=344

int audit_client_db_msg_recv(void)

{
  int iVar1;
  undefined1 local_20 [12];
  
  local_20[0] = 0;
  if (audit_debug_switch != 0) {
    printf("[AUDIT_DBG]%s()/%d rcv msg\n","audit_client_db_msg_recv",0x12e);
  }
  FUN_004082d0(DAT_0076891c,0xffffffff);
  if (DAT_0076890c == 0) {
    iVar1 = 0;
    FUN_00407f30(DAT_0076891c);
  }
  else {
    iVar1 = FUN_004081b0(&audit_msg_queue);
    FUN_00408500(iVar1);
    if (*(int *)(iVar1 + 0xc) == 2) {
      FUN_00408690(DAT_00768910,iVar1);
    }
    if (audit_debug_switch != 0) {
      printf("[AUDIT_DBG]%s()/%d msg list size: %u\n","audit_client_db_msg_recv",0x141,DAT_0076890c)
      ;
    }
    if (DAT_0076890c == 0) {
      read(DAT_00768914,local_20,1);
    }
    FUN_00407f30(DAT_0076891c);
    if (audit_debug_switch != 0) {
      printf("[AUDIT_DBG]%s()/%d rcv msg, type=%d\n","audit_client_db_msg_recv",0x14a,
             *(undefined4 *)(iVar1 + 0xc));
    }
  }
  return iVar1;
}


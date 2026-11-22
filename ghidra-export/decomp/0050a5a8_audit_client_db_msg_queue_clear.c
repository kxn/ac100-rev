// func audit_client_db_msg_queue_clear @ 0050a5a8 size=152

void audit_client_db_msg_queue_clear(void)

{
  int iVar1;
  
  FUN_004082d0(DAT_0076891c,0xffffffff);
  while (DAT_0076890c != 0) {
    iVar1 = FUN_004081b0(&audit_msg_queue);
    FUN_00408500(iVar1);
    if (*(int *)(iVar1 + 0xc) == 2) {
      FUN_00408690(DAT_00768910,iVar1);
    }
    audit_client_db_msg_free(iVar1);
  }
  FUN_00407f30(DAT_0076891c);
  return;
}


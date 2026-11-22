// func _audit_client_thread @ 00508b8c size=480

void _audit_client_thread(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  timeval local_b0;
  fd_set local_a8;
  
  iVar8 = 0;
  uVar1 = audit_client_db_msg_rfd();
  uVar7 = uVar1 >> 5;
  uVar9 = 1 << (uVar1 & 0x1f);
  do {
    while( true ) {
      local_b0.tv_usec = 0;
      iVar8 = iVar8 + 1;
      local_b0.tv_sec = 5;
      iVar2 = 0;
      do {
        puVar5 = (undefined4 *)((int)local_a8.fds_bits + iVar2);
        iVar2 = iVar2 + 4;
        *puVar5 = 0;
      } while (iVar2 != 0x80);
      local_a8.fds_bits[uVar7] = local_a8.fds_bits[uVar7] | uVar9;
      if (audit_debug_switch != 0) {
        printf("[AUDIT_DBG]%s()/%d msg_fd=%d\n","_audit_client_thread",0x2b1,uVar1);
      }
      iVar2 = select(uVar1 + 1,&local_a8,(fd_set *)0x0,(fd_set *)0x0,&local_b0);
      if (iVar2 != 0) break;
      if (audit_debug_switch != 0) {
        printf("[AUDIT_DBG]%s()/%d audit client select timeout %10d\n","_audit_client_thread",0x2b7,
               iVar8);
      }
    }
    if (iVar2 < 1) {
      if (audit_err_switch != 0) {
        printf("[AUDIT_ERR]%s()/%d select error\n","_audit_client_thread",0x2c2);
      }
    }
    else if ((uVar9 & local_a8.fds_bits[uVar7]) != 0) {
      if (audit_debug_switch != 0) {
        printf("[AUDIT_DBG]%s()/%d Try to process messages\n","_audit_client_thread_msg_proc",0x27f)
        ;
      }
      iVar2 = 0x1f5;
      while ((iVar3 = audit_client_db_msg_recv(), iVar3 != 0 && (iVar2 = iVar2 + -1, iVar2 != 0))) {
        uVar6 = audit_auth_sc;
        if (((*(int *)(iVar3 + 0xc) == 1) || (uVar6 = audit_sniffing_sc, *(int *)(iVar3 + 0xc) == 2)
            ) && (iVar4 = FUN_00408540(uVar6,iVar3), iVar4 != 0)) {
          audit_client_db_msg_free(iVar3);
        }
      }
    }
  } while( true );
}


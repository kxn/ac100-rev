// func capwap_dtls_fsm_process @ 00597b14 size=1136

undefined4 capwap_dtls_fsm_process(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  
  if (param_1[0x18] != 0) {
    if (param_1[0x18] != 1) {
      return 0xffffffff;
    }
    iVar2 = FUN_004081b0(param_1[0x10]);
    if ((4 < *(ushort *)(*(undefined4 **)(iVar2 + 0xc) + 1)) &&
       (iVar3 = capwap_packet_is_application(**(undefined4 **)(iVar2 + 0xc)), iVar3 != 0)) {
      return 2;
    }
    FUN_00408500(iVar2);
    cw_pkt_buf_destroy(*(undefined4 *)(iVar2 + 0xc));
    FUN_00407df0(iVar2);
    return 0xffffffff;
  }
  if (*(char *)(param_1 + 0x17) == '\0') {
    iVar2 = FUN_004081b0();
    puVar6 = param_1 + 0x12;
    iVar3 = gnutls_dtls_cookie_verify
                      (param_1 + 0x15,param_1 + 2,0x1c,**(int **)(iVar2 + 0xc) + 4,
                       *(ushort *)(*(int **)(iVar2 + 0xc) + 1) - 4,puVar6);
    if (iVar3 < 0) {
      gnutls_dtls_cookie_send(param_1 + 0x15,param_1 + 2,0x1c,puVar6,param_1 + 1,push_func);
      FUN_00408500(iVar2);
      cw_pkt_buf_destroy(*(undefined4 *)(iVar2 + 0xc));
      FUN_00407df0(iVar2);
      return 0;
    }
    *(undefined1 *)(param_1 + 0x17) = 1;
    gnutls_dtls_prestate_set(*param_1,puVar6);
    iVar2 = gnutls_handshake(*param_1);
    if (iVar2 == -0x34) {
      return 0;
    }
    if (iVar2 == -0x1c) {
      return 0;
    }
    if (iVar2 < 0) {
      if (capwap_warning_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      uVar5 = gnutls_strerror(iVar2);
      printf("[CW_WARNING]%32s():%4d handshake failed:%s\n","capwap_dtls_fsm_process",0x114,uVar5);
      return 0xffffffff;
    }
    if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_DEBUG]%32s():%4d handshake finished\n","capwap_dtls_fsm_process",0x119);
    }
    goto LAB_00597bdc;
  }
  iVar2 = FUN_00408610(param_1[0x10]);
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  if (iVar2 != 0) {
    FUN_0051ad88(&local_54);
    iVar3 = cw_dtls_pkt_parsed(*(undefined4 *)(iVar2 + 0xc),&local_58);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    iVar3 = is_cw_dtls_keoccoehm(&local_58);
    if (iVar3 != 0) {
      if ((*(char *)((int)param_1 + 0x5d) == '\0') &&
         (iVar3 = cw_dtls_pkt_ele_get(&local_58,5), iVar3 != 0)) {
        *(undefined1 *)((int)param_1 + 0x5d) = 1;
      }
      if ((*(char *)((int)param_1 + 0x5e) == '\0') &&
         (iVar3 = cw_dtls_pkt_ele_get(&local_58,6), iVar3 != 0)) {
        *(undefined1 *)((int)param_1 + 0x5e) = 1;
      }
      if ((*(char *)((int)param_1 + 0x5f) == '\0') &&
         (iVar3 = cw_dtls_pkt_ele_get(&local_58,7), iVar3 != 0)) {
        *(undefined1 *)((int)param_1 + 0x5f) = 1;
      }
    }
    cw_dtls_pkt_eles_free(&local_58);
  }
  if (*(char *)((int)param_1 + 0x5d) == '\0') {
    uVar4 = param_1[0x17];
LAB_00597d04:
    if ((uVar4 & 0xffffff) != 0) {
      return 0xffffffff;
    }
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar5 = *param_1;
  }
  else {
    if (*(char *)((int)param_1 + 0x5e) == '\0') {
      uVar4 = param_1[0x17];
      goto LAB_00597d04;
    }
    if (*(char *)((int)param_1 + 0x5f) == '\0') {
      uVar4 = param_1[0x17];
      goto LAB_00597d04;
    }
    uVar5 = *param_1;
  }
  iVar2 = gnutls_handshake(uVar5);
  if (iVar2 == -0x34) {
    return 0;
  }
  if (iVar2 == -0x1c) {
    return 0;
  }
  if (iVar2 < 0) {
    memset(&local_58,0,0x40);
    FUN_00408190(param_1[2],param_1[3],param_1[4],param_1[5],param_1[6],&local_58,0x40,"---");
    if (capwap_warning_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar1 = *(ushort *)(param_1 + 7);
    uVar5 = gnutls_strerror(iVar2);
    printf("[CW_WARNING]%32s():%4d handshake failed[%s:%d]:%s\n","capwap_dtls_fsm_process",0xf6,
           &local_58,(uint)uVar1,uVar5);
    return 0xffffffff;
  }
  memset(&local_58,0,0x40);
  FUN_00408190(param_1[2],param_1[3],param_1[4],param_1[5],param_1[6],&local_58,0x40,"---");
  if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[CW_DEBUG]%32s():%4d handshake finished[%s:%d]\n","capwap_dtls_fsm_process",0xfd,
           &local_58,(uint)*(ushort *)(param_1 + 7));
  }
LAB_00597bdc:
  param_1[0x18] = 1;
  return 1;
}


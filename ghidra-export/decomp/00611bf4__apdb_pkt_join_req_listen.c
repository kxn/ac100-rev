// func _apdb_pkt_join_req_listen @ 00611bf4 size=208

undefined4 _apdb_pkt_join_req_listen(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = (int *)cw_msg_ele_val_get(param_3,0x21);
  if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) {
    puVar2 = (ushort *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x51);
    uVar4 = 0;
    if (puVar2 != (ushort *)0x0) {
      uVar4 = 0xffffffff;
      if ((0xf < *puVar2) &&
         (iVar3 = _apdb_pkt_manage(*(undefined4 *)(puVar2 + 2),*puVar2,param_1,param_2,param_3),
         iVar3 != -1)) {
        uVar4 = 0;
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : Failed to join for formal callback return failed result code.\n"
             ,"_apdb_pkt_join_req_listen",0x871);
    }
  }
  return uVar4;
}


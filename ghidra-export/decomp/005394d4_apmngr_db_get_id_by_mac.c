// func apmngr_db_get_id_by_mac @ 005394d4 size=108

undefined2 apmngr_db_get_id_by_mac(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = 0xffff;
  if (param_1 != 0) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    iVar1 = FUN_00407fa0(g_apmngr_ap_hash,param_1);
    if (iVar1 != 0) {
      uVar2 = *(undefined2 *)(iVar1 + 0x10);
    }
    FUN_00407f30(apmngr_db_mutex);
  }
  return uVar2;
}


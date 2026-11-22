// func cw_priv_sta_assoc_req_new_free @ 005c24b4 size=72

undefined4 cw_priv_sta_assoc_req_new_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    cw_sta_assoc_req_sub_ele_free(iVar1);
    FUN_00407df0(iVar1);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}


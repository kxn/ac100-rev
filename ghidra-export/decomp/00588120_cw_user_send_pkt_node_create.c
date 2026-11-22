// func cw_user_send_pkt_node_create @ 00588120 size=124

int cw_user_send_pkt_node_create(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00408450(0x10,0x4d2);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)cw_send_pkt_create(0xfa,0);
    *(undefined4 **)(iVar1 + 0xc) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      FUN_00407df0(iVar1);
      iVar1 = 0;
    }
    else {
      *puVar2 = param_1;
      *(undefined4 *)(*(int *)(iVar1 + 0xc) + 4) = param_2;
    }
  }
  return iVar1;
}


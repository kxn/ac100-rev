// func _apmngr_child_router_enter_reset @ 00554a10 size=56

undefined4 _apmngr_child_router_enter_reset(int param_1,ushort *param_2)

{
  if ((int)*(short *)(param_1 + 0x18) == (uint)*param_2) {
    apmngr_ap_try_delete(*(undefined2 *)(param_1 + 0x10));
  }
  return 0;
}


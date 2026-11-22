// func cw_priv_ap_wire_vlan_2_free @ 005aa8a0 size=60

undefined4 cw_priv_ap_wire_vlan_2_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00407df0();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}


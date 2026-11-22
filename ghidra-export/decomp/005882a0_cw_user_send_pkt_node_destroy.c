// func cw_user_send_pkt_node_destroy @ 005882a0 size=76

void cw_user_send_pkt_node_destroy(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    cw_send_pkt_destroy();
  }
  FUN_00407df0(param_1);
  return;
}


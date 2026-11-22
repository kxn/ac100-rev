// func cw_priv_mesh_private_control_free @ 0057b0b4 size=60

undefined4 cw_priv_mesh_private_control_free(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    cw_priv_mesh_private_control_val_destroy();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}


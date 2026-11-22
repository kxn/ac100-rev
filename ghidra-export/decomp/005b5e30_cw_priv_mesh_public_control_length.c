// func cw_priv_mesh_public_control_length @ 005b5e30 size=32

short cw_priv_mesh_public_control_length(short *param_1)

{
  return param_1[4] + 4 + *param_1 * 6;
}


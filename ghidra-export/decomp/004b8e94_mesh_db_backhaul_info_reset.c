// func mesh_db_backhaul_info_reset @ 004b8e94 size=1

undefined4 mesh_db_backhaul_info_reset(void)

{
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  memcpy(&DAT_00767ebd,&dft_backhaul_info,0x82);
  FUN_00407f30(DAT_00767eb4);
  return 0;
}


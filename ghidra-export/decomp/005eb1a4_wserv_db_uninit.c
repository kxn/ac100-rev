// func wserv_db_uninit @ 005eb1a4 size=992

undefined4 wserv_db_uninit(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_28 [3];
  
  local_28[0] = 0;
  if (l_wserv_data == 0) {
    if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[error]%s(): %d  -> wserv data has not been inited yet!\r\n","wserv_db_uninit",
             0x807);
    }
  }
  else {
    iVar2 = FUN_004081b0(&DAT_007cbf18);
    while (iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
      iVar2 = iVar3;
    }
    iVar2 = FUN_004081b0(&DAT_007cbf24);
    while (iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
      iVar2 = iVar3;
    }
    iVar2 = FUN_004081b0(&DAT_007cbf30);
    while (iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
      iVar2 = iVar3;
    }
    iVar2 = FUN_004081b0(&DAT_007cbf3c);
    while (iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      FUN_00408500(iVar2);
      FUN_00407df0(iVar2);
      iVar2 = iVar3;
    }
    if (DAT_007cbf08 != 0) {
      for (local_28[0] = 0; (int)local_28[0] < 0x1000; local_28[0] = local_28[0] + 1) {
        iVar2 = *(int *)(DAT_007cbf08 + local_28[0] * 4);
        if (iVar2 != 0) {
          FUN_00408570(iVar2,_wserv_del_ap_hash_cb,local_28);
          FUN_00408310(*(undefined4 *)(DAT_007cbf08 + local_28[0] * 4));
          *(undefined4 *)(DAT_007cbf08 + local_28[0] * 4) = 0;
        }
      }
      FUN_00407df0(DAT_007cbf08);
      DAT_007cbf08 = 0;
    }
    if (DAT_007cbefc != 0) {
      for (local_28[0] = 0; local_28[0] < l_wserv_profile; local_28[0] = local_28[0] + 1) {
        iVar2 = DAT_007cbefc + local_28[0] * 0x21c;
        if (*(int *)(iVar2 + 0xc) != 0) {
          iVar2 = *(int *)(iVar2 + 0x218);
          if (iVar2 != 0) {
            FUN_00408570(iVar2,_wserv_del_rd_hash_cb,local_28);
            FUN_00408310(*(undefined4 *)(DAT_007cbefc + local_28[0] * 0x21c + 0x218));
            *(undefined4 *)(DAT_007cbefc + local_28[0] * 0x21c + 0x218) = 0;
          }
        }
      }
      FUN_00407df0(DAT_007cbefc);
      DAT_007cbefc = 0;
    }
    if (DAT_007cbf04 != 0) {
      local_28[0] = 0;
      while( true ) {
        uVar1 = local_28[0];
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar4 = apmngr_db_get_sensor_max();
        iVar5 = rdmngr_profile_get_max_rd_per_ap();
        if ((uint)((iVar2 + iVar3 + iVar4) * iVar5) <= uVar1) break;
        if (*(int *)(DAT_007cbf04 + local_28[0] * 0xc + 8) != 0) {
          FUN_00407df0();
          *(undefined4 *)(DAT_007cbf04 + local_28[0] * 0xc + 8) = 0;
        }
        local_28[0] = local_28[0] + 1;
      }
      FUN_00407df0(DAT_007cbf04);
      DAT_007cbf04 = 0;
    }
    if (DAT_007cbef4 != 0) {
      FUN_00408160();
      DAT_007cbef4 = 0;
    }
    if (DAT_007cbf0c != 0) {
      FUN_00408160();
      DAT_007cbf0c = 0;
    }
    if (DAT_007cbf14 != 0) {
      FUN_00407df0();
      DAT_007cbf14 = 0;
    }
    if (DAT_007cbef0 != 0) {
      FUN_00408360();
      DAT_007cbef0 = 0;
    }
    l_wserv_data = 0;
    DAT_007cbf00 = 0;
    DAT_007cbef8 = 0;
  }
  return 0;
}


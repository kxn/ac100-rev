// func rdmngr_dbg_idx_clear @ 00621e9c size=1

void rdmngr_dbg_idx_clear(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = rdmngr_db_generate_rd_idx_by_rd_id();
  iVar1 = DAT_007cc65c;
  if ((g_rdmngr_dbg_idx != 0) && (-1 < (int)uVar2)) {
    iVar3 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    iVar5 = apmngr_db_get_sensor_max();
    if (uVar2 < (uint)((iVar3 + iVar4 + iVar5) * iVar1)) {
      *(undefined1 *)(g_rdmngr_dbg_idx + uVar2) = 0;
    }
  }
  return;
}


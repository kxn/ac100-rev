// func _wserv_db_info_collect @ 005e9ff8 size=388

void _wserv_db_info_collect(undefined4 *param_1,int param_2)

{
  byte bVar1;
  void *__src;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_1 + 1);
  uVar4 = *param_1;
  __src = (void *)_wserv_get_entry(uVar4,(uint)bVar1);
  if (__src == (void *)0x0) {
    if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> _wserv_get_entry() fail, rf/wlan[%d/%d]!\r\n",
             "_wserv_db_info_collect",0x5cf,*param_1,(uint)*(byte *)(param_1 + 1));
    }
  }
  else {
    iVar2 = wserv_calloc(1,0x220);
    if (iVar2 != 0) {
      memcpy((void *)(iVar2 + 0x1a),__src,0x205);
      *(undefined4 *)(iVar2 + 0x10) = uVar4;
      *(byte *)(iVar2 + 0x14) = bVar1;
      iVar3 = rdmngr_db_generate_rd_idx_by_rd_id(uVar4);
      *(undefined2 *)(iVar2 + 0x212) =
           *(undefined2 *)(*(int *)(DAT_007cbf04 + iVar3 * 0xc + 8) + (bVar1 - 1) * 6 + 4);
      FUN_004086b0(param_2 + 4,iVar2);
      return;
    }
    if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> no memory!!\r\n","_wserv_db_info_collect",0x5d6);
      return;
    }
  }
  return;
}


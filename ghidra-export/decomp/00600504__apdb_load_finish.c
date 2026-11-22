// func _apdb_load_finish @ 00600504 size=304

undefined4 _apdb_load_finish(void)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  
  if (l_apdb_ap_item_new == 0) {
    uVar2 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : you haven\'t loaded new apdb.\n","_apdb_load_finish",0x10c0
            );
    }
  }
  else {
    if (l_apdb_ap_item_cur != (void *)0x0) {
      _apdb_ap_item_free(l_apdb_ap_item_cur,l_apdb_ap_item_cnt_cur);
      l_apdb_ap_item_cur = (void *)0x0;
    }
    l_apdb_ap_item_cnt_cur = l_apdb_ap_item_cnt_new;
    if (0 < l_apdb_ap_item_cnt_new) {
      __s = (void *)FUN_00408450(l_apdb_ap_item_cnt_new * 0x58,0x10d0);
      iVar1 = l_apdb_ap_item_cnt_cur;
      l_apdb_ap_item_cur = __s;
      if (__s == (void *)0x0) {
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : malloc l_apdb_ap_item_cur failed.\n",
                 "_apdb_load_finish",0x10d3);
        }
        _apdb_free_all_db();
        return 0xffffffff;
      }
      memset(__s,0,l_apdb_ap_item_cnt_cur * 0x58);
      _apdb_ap_item_copy(__s,l_apdb_ap_item_new,iVar1);
    }
    uVar2 = 0;
    _apdb_free_new_db();
  }
  return uVar2;
}


// func _wportal_page_del_all @ 004102d4 size=272

undefined4 _wportal_page_del_all(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_180 [308];
  int local_4c;
  
  if (g_portal_auth_mode == 1) {
    iVar2 = 1;
    do {
      memset(auStack_180,0,0x16c);
      wportal_db_rdt_get_by_vlan(iVar2,auStack_180);
      if (local_4c != 0) {
        wportal_db_rdt_del(iVar2);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x1000);
  }
  else {
    uVar3 = 0;
    if (g_portal_auth_mode == 0) {
      while (uVar1 = wserv_profile_get_max_wservice(), uVar3 < uVar1) {
        memset(auStack_180,0,0x16c);
        iVar2 = wportal_db_ssid_rdt_get(uVar3,auStack_180);
        if (iVar2 == 0) {
          wserv_db_entry_for_each_rd(uVar3,_wportal_wserv_del_rdt_ftt,auStack_180);
          wportal_db_ssid_rdt_del(uVar3);
          uVar3 = uVar3 + 1;
        }
        else {
          uVar3 = uVar3 + 1;
        }
      }
    }
    else if (g_portal_auth_mode == 2) {
      wportal_db_iface_del_all();
    }
  }
  return 0;
}


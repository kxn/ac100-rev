// func mesh_db_discover_list_get @ 004b99ec size=660

undefined4 mesh_db_discover_list_get(int param_1,int *param_2,int param_3,int param_4)

{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  void *__src;
  undefined1 auStack_300 [24];
  short local_2e8;
  
  uVar3 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    memset(auStack_300,0,0x2d8);
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    iVar4 = FUN_00407fe0(&DAT_00767f5c);
    if (iVar4 == 0) {
      FUN_00407f30(DAT_00767eb4);
      if (mesh_debug_switch == '\0') {
        *param_2 = 0;
      }
      else {
        printf("[MESH_DEBUG]%s()/%d MESH_AP_DISCOVER_LIST size=0\n","mesh_db_discover_list_get",
               0x5e0);
        *param_2 = 0;
      }
      uVar3 = 0;
    }
    else {
      iVar4 = FUN_004081b0(&DAT_00767f5c);
      iVar7 = 0;
      if (iVar4 != 0) {
        bVar2 = true;
        while (bVar2) {
          if (param_3 == *(int *)(iVar4 + 100)) {
            __src = (void *)(iVar4 + 0xc);
            if (param_4 == 0) {
              iVar5 = iVar7 * 6;
              iVar7 = iVar7 + 1;
              memcpy((void *)(param_1 + iVar5),__src,6);
            }
            else {
              iVar5 = apmngr_db_entry_get_by_mac(__src,auStack_300);
              if (iVar5 == -1) {
                if (mesh_debug_switch != '\0') {
                  printf("[MESH_DEBUG]%s()/%d do not find need auto pair re entry\n",
                         "mesh_db_discover_list_get",0x5fc);
                }
              }
              else {
                for (iVar5 = FUN_004081b0(iVar4 + 0x58); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
                  if (mesh_debug_switch == '\0') {
                    uVar1 = *(ushort *)(iVar5 + 0xc);
                  }
                  else {
                    printf("[MESH_DEBUG]%s()/%d link_info_entry->cap_id=%d, link_info_entry->pap_id=%d, ap_entry.cap_id=%d\n"
                           ,"mesh_db_discover_list_get",0x607,(uint)*(ushort *)(iVar5 + 0xc),
                           (uint)*(ushort *)(iVar5 + 0xe),(int)local_2e8);
                    uVar1 = *(ushort *)(iVar5 + 0xc);
                  }
                  if ((uint)uVar1 == (int)local_2e8) {
                    if (mesh_debug_switch != '\0') {
                      printf("[MESH_DEBUG]%s()/%d find need auto pair re entry\n",
                             "mesh_db_discover_list_get",0x60a);
                    }
                    iVar6 = iVar7 * 6;
                    iVar7 = iVar7 + 1;
                    memcpy((void *)(param_1 + iVar6),__src,6);
                  }
                }
              }
            }
          }
          else if (mesh_debug_switch != '\0') {
            printf("[MESH_DEBUG]%s()/%d state not match, state_filter=%d, discover_entry->state=%d\n"
                   ,"mesh_db_discover_list_get",0x5f2,param_3,*(int *)(iVar4 + 100));
          }
          iVar4 = FUN_00408680(iVar4);
          if (iVar4 == 0) break;
          bVar2 = iVar7 < 0x80;
        }
      }
      *param_2 = iVar7;
      FUN_00407f30(DAT_00767eb4);
      uVar3 = 0;
    }
  }
  return uVar3;
}


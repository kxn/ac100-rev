// func _mesh_auto_pair_task @ 004baec0 size=620

void _mesh_auto_pair_task(void)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined1 *__src;
  int local_738;
  int local_734;
  undefined1 auStack_730 [304];
  undefined1 auStack_600 [16];
  ushort local_5f0;
  short local_5e8;
  undefined1 auStack_328 [768];
  
  memset(auStack_600,0,0x2d8);
  memset(auStack_730,0,300);
  local_734 = 0;
  memset(auStack_328,0,0x300);
  local_738 = 0;
LAB_004baf44:
  while( true ) {
    while( true ) {
      do {
        do {
          sleep(1);
          iVar1 = mesh_db_re_auto_add_state_get(&local_734);
        } while (iVar1 == -1);
      } while ((local_734 != 1) || (iVar1 = mesh_db_discover_state_get(), iVar1 != 1));
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d auto_pair_task RUN\n","_mesh_auto_pair_task",0x78c);
      }
      iVar1 = mesh_db_discover_list_get(auStack_328,&local_738,0,1);
      if (iVar1 != -1) break;
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d mesh_db_discover_list_get fail\n","_mesh_auto_pair_task",0x790);
      }
    }
    if (0 < local_738) break;
    if (mesh_debug_switch != '\0') {
      uVar3 = 0x796;
      __format = "[MESH_DEBUG]%s()/%d find no re need to auto_pair, mac_num=%d\n";
      iVar1 = local_738;
LAB_004bb0e8:
      printf(__format,"_mesh_auto_pair_task",uVar3,iVar1);
    }
  }
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d find re need to auto_pair, mac_num=%d\n","_mesh_auto_pair_task",
           0x799);
  }
  iVar1 = 0;
  __src = auStack_328;
  do {
    while( true ) {
      if ((local_738 <= iVar1) || (0x7f < local_738)) goto LAB_004baf44;
      iVar2 = apmngr_db_entry_get_by_mac(auStack_328 + iVar1 * 6,auStack_600);
      if (iVar2 != -1) break;
LAB_004bb058:
      iVar1 = iVar1 + 1;
      __src = __src + 6;
    }
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d find existed discover_RE need to auto_pair, re_id=%d, cap_id=%d\n"
             ,"_mesh_auto_pair_task",0x7a7,(uint)local_5f0,(int)local_5e8);
    }
    memcpy(auStack_730,__src,6);
    iVar2 = mesh_pkt_re_operation_request_send((int)local_5e8,1,auStack_730,0);
    if (iVar2 != 0) {
      if (mesh_err_switch != '\0') {
        __format = "[MESH_ERROR]%s()/%d Auto Send pair request to AP(%d) failed!\n";
        uVar3 = 0x7ab;
        iVar1 = (int)local_5e8;
        goto LAB_004bb0e8;
      }
      goto LAB_004baf44;
    }
    iVar2 = mesh_db_discover_pair_state_update(auStack_730,1,1);
    if ((iVar2 == 0) || (mesh_err_switch == '\0')) goto LAB_004bb058;
    printf("[MESH_ERROR]%s()/%d Auto Refresh discover pair state failed!\n","_mesh_auto_pair_task",
           0x7b0);
    iVar1 = iVar1 + 1;
    __src = __src + 6;
  } while( true );
}


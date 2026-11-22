// func mesh_re_entry_delete @ 004bc5c8 size=104

undefined4 mesh_re_entry_delete(ushort param_1)

{
  ushort local_res0 [8];
  
  local_res0[0] = param_1;
  if (mesh_debug_switch != '\0') {
    printf("[MESH_DEBUG]%s()/%d Delete %d mesh child ap\n","mesh_re_entry_delete",0x2fc,
           (uint)param_1);
  }
  apmngr_ap_delete(local_res0,1,0,0,1);
  mesh_db_ap_entry_delete(local_res0[0]);
  return 0;
}


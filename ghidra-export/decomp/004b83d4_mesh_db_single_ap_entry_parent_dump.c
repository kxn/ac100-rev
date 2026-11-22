// func mesh_db_single_ap_entry_parent_dump @ 004b83d4 size=1

void mesh_db_single_ap_entry_parent_dump(undefined2 param_1)

{
  undefined4 auStack_10 [3];
  
  auStack_10[0] = 0;
  mesh_db_ap_entry_parent_foreach_proc(param_1,1,_mesh_db_single_ap_entry_parent_dump,auStack_10);
  return;
}


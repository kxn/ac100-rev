// func _mesh_ap_entry_travesal @ 004bb294 size=68

undefined4 _mesh_ap_entry_travesal(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = mesh_db_ap_entry_child_foreach_proc
                    (*(undefined2 *)(param_1 + 0x10),0,_mesh_ap_entry_topology_get,param_2);
  uVar2 = 1;
  if ((iVar1 != 1) && (uVar2 = 2, iVar1 != 2)) {
    uVar2 = 0;
  }
  return uVar2;
}


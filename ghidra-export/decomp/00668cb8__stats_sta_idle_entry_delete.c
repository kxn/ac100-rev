// func _stats_sta_idle_entry_delete @ 00668cb8 size=48

void _stats_sta_idle_entry_delete(int param_1,uint *param_2)

{
  if (((param_1 != 0) && (*(uint *)(param_1 + 0x40) != 0)) &&
     (*(uint *)(param_1 + 0x40) <= *param_2)) {
    _stats_sta_free_entry();
    return;
  }
  return;
}


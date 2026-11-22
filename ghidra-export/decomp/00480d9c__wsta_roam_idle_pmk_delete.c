// func _wsta_roam_idle_pmk_delete @ 00480d9c size=84

void _wsta_roam_idle_pmk_delete(int param_1,uint *param_2)

{
  if (param_1 != 0) {
    if (((*(int *)(DAT_00767548 + *(int *)(param_1 + 4) * 0x4c) != 0) &&
        (*(uint *)(param_1 + 0x48) != 0)) && (*(uint *)(param_1 + 0x48) <= *param_2)) {
      _wsta_roam_free_pmk();
      return;
    }
  }
  return;
}


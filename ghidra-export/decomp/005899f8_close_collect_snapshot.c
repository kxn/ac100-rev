// func close_collect_snapshot @ 005899f8 size=1

void close_collect_snapshot(void)

{
  open_store_snapshot = 0;
  (*(code *)PTR_remove_00758ffc)("/tmp/old_pkt_snapshot.csv");
  return;
}


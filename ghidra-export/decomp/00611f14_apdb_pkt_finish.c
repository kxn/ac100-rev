// func apdb_pkt_finish @ 00611f14 size=56

void apdb_pkt_finish(void)

{
  if (apdb_pkt_mutex != 0) {
    FUN_00408360();
    apdb_pkt_mutex = 0;
  }
  return;
}


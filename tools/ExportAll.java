// Full-corpus export for uac: index of all functions, decompiled C per function,
// and defined strings. Run headless:
//   analyzeHeadless <projdir> acap -process uac -noanalysis \
//     -scriptPath <repo>/tools -postScript ExportAll.java <repo>/ghidra-export
// @category ACAP
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.Symbol;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class ExportAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args[0];
        Files.createDirectories(Paths.get(outDir, "decomp"));

        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        ifc.setOptions(opts);
        ifc.openProgram(currentProgram);

        FunctionManager fm = currentProgram.getFunctionManager();
        StringBuilder index = new StringBuilder();
        int n = 0, fail = 0;
        for (Function f : fm.getFunctions(true)) {
            Address ep = f.getEntryPoint();
            long size = f.getBody().getNumAddresses();
            String name = f.getName();
            String fname = ep.toString().replace(":", "") + "_" + sanitize(name) + ".c";
            index.append(ep).append(',').append(size).append(',').append(name).append('\n');
            StringBuilder sb = new StringBuilder();
            sb.append("// func ").append(name).append(" @ ").append(ep)
              .append(" size=").append(size).append('\n');
            DecompileResults res = ifc.decompileFunction(f, 120, monitor);
            if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                sb.append(res.getDecompiledFunction().getC());
            } else {
                fail++;
                sb.append("// decompile failed: ")
                  .append(res == null ? "null" : String.valueOf(res.getErrorMessage())).append('\n');
            }
            Files.write(Paths.get(outDir, "decomp", fname), sb.toString().getBytes("UTF-8"));
            n++;
            if (n % 250 == 0) println("exported " + n + " functions");
        }
        Files.write(Paths.get(outDir, "index.csv"), index.toString().getBytes("UTF-8"));
        println("ExportAll: functions=" + n + " failed=" + fail);

        // Defined strings
        StringBuilder sbs = new StringBuilder();
        for (Iterator<?> it = currentProgram.getListing().getDefinedData(true).iterator(); it.hasNext(); ) {
            Data d = (Data) it.next();
            Object v = d.getValue();
            if (d.hasStringValue() && v != null) {
                sbs.append(d.getAddress()).append('\t').append(v.toString().replace("\n", "\\n")).append('\n');
            }
        }
        Files.write(Paths.get(outDir, "strings.txt"), sbs.toString().getBytes("UTF-8"));
        println("ExportAll done");
    }

    private String sanitize(String s) {
        return s.replaceAll("[^A-Za-z0-9_$._]", "_");
    }
}

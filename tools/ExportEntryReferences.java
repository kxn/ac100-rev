// @category AC100
// Export code references in registration roots; no firmware is executed.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.nio.file.*;
import java.util.*;

public class ExportEntryReferences extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        List<String> rows = new ArrayList<>();
        Map<Long, String> symbols = new HashMap<>();
        for (String line : Files.readAllLines(Paths.get(args[2]))) {
            String[] fields = line.trim().split("\\s+", 4);
            if (fields.length == 4) symbols.put(Long.parseLong(fields[0], 16), fields[3]);
        }
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (!f.getName().matches(args[1])) continue;
            for (Instruction i : currentProgram.getListing().getInstructions(f.getBody(), true)) {
                for (Reference r : i.getReferencesFrom()) {
                    String target = symbols.get(r.getToAddress().getOffset());
                    if (target == null || r.getReferenceType().isFlow()) continue;
                    rows.add(f.getName() + "\t" + i.getAddress() + "\t" + target + "\t" + r.getToAddress());
                }
            }
        }
        Collections.sort(rows);
        Files.write(Paths.get(args[0]), rows);
        println("Exported " + rows.size() + " function-address references");
    }
}

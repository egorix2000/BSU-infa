
public enum CoffeeType {
    GROUND("Ground"),
    INSTANT("Instant"),
    BEANS("Beans");

    private final String typeName;
    CoffeeType(String typeName){
        this.typeName = typeName;
    }

    public static CoffeeType toType(String s) throws EnumIncorrectException {
        CoffeeType temp;
        switch (s) {
            case "GROUND":
                temp = GROUND;
                break;
            case "INSTANT":
                temp = INSTANT;
                break;
            case "BEANS":
                temp = BEANS;
                break;
            default:
                throw new EnumIncorrectException();
        }
        return temp;
    }
}

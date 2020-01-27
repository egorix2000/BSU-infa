public enum TeaType {
    GREEN("Green"),
    BLACK("Black"),
    YELLOW("Yellow"),
    WHITE("White");

    private final String typeName;
    TeaType(String typeName){
        this.typeName = typeName;
    }

    public static TeaType toType(String s) throws EnumIncorrectException {
        TeaType temp;
        switch (s) {
            case "GREEN":
                temp = GREEN;
                break;
            case "BLACK":
                temp = BLACK;
                break;
            case "YELLOW":
                temp = YELLOW;
                break;
            case "WHITE":
                temp = WHITE;
                break;
            default:
                throw new EnumIncorrectException();
        }
        return temp;
    }
}

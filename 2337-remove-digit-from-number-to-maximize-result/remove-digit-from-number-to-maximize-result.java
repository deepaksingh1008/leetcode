class Solution {
    public String removeDigit(String number, char digit) {
        
        String largestNumber = "";
        
        for(int i=0;i<number.length();i++){
            if(number.charAt(i) == digit){
                 String newNumber = number.substring(0,i) + number.substring(i+1);
                if(newNumber.compareTo(largestNumber)>0){
                    largestNumber = newNumber;
                }
            }
            
        }
        return largestNumber;
    }
}
class Solution {
    public String findLargest(int[] arr) {
       StringBuilder str = new StringBuilder();
        List<String> list = new ArrayList<>();
        for (int val : arr) {
            list.add(String.valueOf(val));
        }

        
        list.sort((a,b)-> (b+a).compareTo(a+b));

        
        if (list.get(0).equals("0")) {
            return "0";
        }
         
        for (String s : list) {
            str.append(s);
        }

        return str.toString();
    }
}
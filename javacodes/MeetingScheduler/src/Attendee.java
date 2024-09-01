public class Attendee {
    AttendeeCalender calender;
    String name;
    public Attendee(String name){
        this.name = name;
        calender = new AttendeeCalender();
    }
    public boolean isAvailable(int start, int end) {
        return calender.isAvailable(start,end);
    }

    public void scheduleMeeting(Meeting meeting){
        calender.scheduleMeeting(meeting,name);
    }

    public void notifyAttendee(Meeting meeting){
        System.out.println("You have meeting meeting details are: " + name);
    }
}

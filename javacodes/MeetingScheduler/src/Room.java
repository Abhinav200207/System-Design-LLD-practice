import java.util.List;

public class Room {
    RoomCalender calendar;
    int id;
    public Room (int id) {
        this.id = id;
        calendar = new RoomCalender();
    }

    public Meeting scheduleMeeting(int start, int end, List<Attendee> attendeeList) {
        return calendar.scheduleMeeting(start,end,attendeeList,this);
    }

    public boolean isAvailable(int start, int end) {
        return calendar.checkAvailability(start, end);
    }
}
